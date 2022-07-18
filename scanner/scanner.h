#pragma once

#include "../system/proc.h"
#include "../util/feature.h"

class Scanner : public Feature {
    ProcMeta target;
    std::string title;
public:
    Scanner(ProcMeta target);
    virtual ~Scanner();
    virtual void Render();
};