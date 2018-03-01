#include "Params.h"

#include <fstream>

Params::Params(const std::string& filename) {
    std::ifstream ifs(filename);
    json j;
    ifs >> j;
}

void Params::buildMap() {
    std::unordered_map<std::string, sf::Keyboard::Key> str2key;
    std::unordered_map<sf::Keyboard::Key, std::string> key2str;
#ifdef ADDKEY
#error "Macro `ADDKEY` is already defined"
#endif
#define ADDKEY(k) \
    do { \
        str2key.insert(std::make_pair(#k, sf::Keyboard::Key::k)); \
        key2str.insert(std::make_pair(sf::Keyboard::Key::k, #k)); \
    } while(false)

    ADDKEY(A);
    ADDKEY(B);
    ADDKEY(C);
    ADDKEY(D);
    ADDKEY(E);
    ADDKEY(F);
    ADDKEY(G);
    ADDKEY(H);
    ADDKEY(I);
    ADDKEY(J);
    ADDKEY(K);
    ADDKEY(L);
    ADDKEY(M);
    ADDKEY(N);
    ADDKEY(O);
    ADDKEY(P);
    ADDKEY(Q);
    ADDKEY(R);
    ADDKEY(S);
    ADDKEY(T);
    ADDKEY(U);
    ADDKEY(V);
    ADDKEY(W);
    ADDKEY(X);
    ADDKEY(Y);
    ADDKEY(Z);
    ADDKEY(Num0);
    ADDKEY(Num1);
    ADDKEY(Num2);
    ADDKEY(Num3);
    ADDKEY(Num4);
    ADDKEY(Num5);
    ADDKEY(Num6);
    ADDKEY(Num7);
    ADDKEY(Num8);
    ADDKEY(Num9);
    ADDKEY(Escape);
    ADDKEY(LControl);
    ADDKEY(LShift);
    ADDKEY(LAlt);
    ADDKEY(LSystem);
    ADDKEY(RControl);
    ADDKEY(RShift);
    ADDKEY(RAlt);
    ADDKEY(RSystem);
    ADDKEY(Menu);
    ADDKEY(LBracket);
    ADDKEY(RBracket);
    ADDKEY(SemiColon);
    ADDKEY(Comma);
    ADDKEY(Period);
    ADDKEY(Quote);
    ADDKEY(Slash);
    ADDKEY(BackSlash);
    ADDKEY(Tilde);
    ADDKEY(Equal);
    ADDKEY(Dash);
    ADDKEY(Space);
    ADDKEY(Return);
    ADDKEY(BackSpace);
    ADDKEY(Tab);
    ADDKEY(PageUp);
    ADDKEY(PageDown);
    ADDKEY(End);
    ADDKEY(Home);
    ADDKEY(Insert);
    ADDKEY(Delete);
    ADDKEY(Add);
    ADDKEY(Subtract);
    ADDKEY(Multiply);
    ADDKEY(Divide);
    ADDKEY(Left);
    ADDKEY(Right);
    ADDKEY(Up);
    ADDKEY(Down);
    ADDKEY(Numpad0);
    ADDKEY(Numpad1);
    ADDKEY(Numpad2);
    ADDKEY(Numpad3);
    ADDKEY(Numpad4);
    ADDKEY(Numpad5);
    ADDKEY(Numpad6);
    ADDKEY(Numpad7);
    ADDKEY(Numpad8);
    ADDKEY(Numpad9);
    ADDKEY(F1);
    ADDKEY(F2);
    ADDKEY(F3);
    ADDKEY(F4);
    ADDKEY(F5);
    ADDKEY(F6);
    ADDKEY(F7);
    ADDKEY(F8);
    ADDKEY(F9);
    ADDKEY(F10);
    ADDKEY(F11);
    ADDKEY(F12);
    ADDKEY(F13);
    ADDKEY(F14);
    ADDKEY(F15);
    ADDKEY(Pause);

    assert(str2key.size() == sf::Keyboard::Key::KeyCount);
    assert(key2str.size() == sf::Keyboard::Key::KeyCount);

#undef ADDKEY

#ifdef ADDEVT
#error "Macro `ADDEVT` is already defined"
#endif
#define ADDEVT(k) \
    do { \
        str2evt.insert(std::make_pair(#k, Event::k)); \
        evt2str.insert(std::make_pair(Event::k, #k)); \
    } while(false)

    ADDEVT(Meh);
    ADDEVT(Moh);

    assert(str2evt.size() == Event::Count);
    assert(evt2str.size() == Event::Count);

#undef ADDEVT

}


void Params::readGraphics(const json& j) {
    if(!j.is_object()) return;
    json::const_iterator it;
    if((it = j.find("windowSize")) != j.end()) {
        jsonToVector2u(*it, graphics.windowSize);
    }
    if((it = j.find("fullscreen")) != j.end() && it->is_boolean()) {
        graphics.fullscreen = *it;
    }
}

void Params::readEvents(const json& j) {
    if(!j.is_object()) return;
    for(size_t i = 0; i < Event::Count; ++i) {
        events[i] = std::nullopt;
    }
    for(json::const_iterator it = j.begin(); it != j.end(); ++it) {
        if(str2evt.count(it.value()) && str2key.count(it.key())) {
            events[str2evt[it.value()]] = str2key[it.key()];
        }
    }
}
