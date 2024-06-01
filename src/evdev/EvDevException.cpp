//
// Created by thonkdifferent on 01.06.24.
//

#include "EvDevException.h"

const char * EvDevException::what() const noexcept {
    std::stringstream buffer;
    buffer<<"LibEvDev failed at function call: \""<<m_message<<"\" Please report this issue";
    return exception::what();
}
