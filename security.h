#ifndef SECURITY_H
#define SECURITY_H

#include <string>
#include <unordered_map>

bool loginSystem();
std::string customSha256(const std::string& input);

#endif // SECURITY_H
