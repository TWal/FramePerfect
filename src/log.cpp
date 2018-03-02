#include "log.h"

namespace lg{
    using namespace std;
    using namespace spdlog;


    static spdlog::level::level_enum compile_lvl = spdlog::level::LOG_LEVEL;

#define LOG_DECL(name, lvl)                                             \
    unique_ptr<logger> name;                                            \
    static spdlog::level::level_enum name##_lvl = spdlog::level::lvl;

    LOG_DECL(base,info)
    LOG_DECL(event,trace)
    LOG_DECL(gui,info)
    LOG_DECL(phy,info)
    LOG_DECL(history,info)
    LOG_DECL(render,info)

    void init(){
        auto stdoutSink = make_shared<sinks::ansicolor_stdout_sink_st>();
        auto fileSink = make_shared<sinks::simple_file_sink_st>(LOG_FILE);
        vector<shared_ptr<sinks::sink>> v = {stdoutSink,fileSink};

#define LOG_CREAT(name)                                         \
        name = make_unique<logger>(#name,v.begin(), v.end());   \
        name->flush_on(spdlog::level::err);                     \
        name->set_level(max(name##_lvl,compile_lvl));

        LOG_CREAT(base);
        LOG_CREAT(event);
        LOG_CREAT(gui);
        LOG_CREAT(phy);
        LOG_CREAT(history);
        LOG_CREAT(render);

        base->info("Log system on to file {}", LOG_FILE);
    }
}
