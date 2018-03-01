#pragma once

#include "Model.h"

class Level{
    using sModel = std::shared_ptr<Model>;
    Level() = delete;
    struct Branch{
        struct BFrame{
            sModel base;
            std::vector<Patch> patches; /// max size : BFRAME_SIZE
        };
        std::vector<Branch*> nexts;
        std::vector<BFrame> frames;
        sModel end;
        /// nullptr mean this is a root branch, i.e data[0]->base is the initial state
        Branch* parent;
        Model build(u64 index);
        };
    std::vector<std::unique_ptr<Branch>> branches; // just to mark ownership.
    std::vector<Branch*> currentPath;
    Branch* currentBranch; ///< should be in currentPath.
    u64 current_index;
    sModel currentModel;
public:
    const Model& last() const {return *(currentPath.back()->end);}
    /// The model of current position in time.
    const Model& current() const {return *currentModel;}
};
