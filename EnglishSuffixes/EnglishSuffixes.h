#pragma once


#include <string>
#include <string_view>

namespace ens
{
// Do not include headers within a namespace.
// If you do, you may include the same code multiple times in namespaces.
// Then, due to `#pragma once`, you do not know which namespace a header is actually included.

std::string addSuffix(std::string_view word, const std::string& suffix);

}