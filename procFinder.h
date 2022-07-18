#pragma once

#include <string>
#include <vector>
#include "proc.h"

namespace ProcFinder {
    const std::vector<ProcMeta>& GetAllProcs();
    const std::vector<ProcMeta>& UpdateProcList();
};