#ifndef INVALID_POINTER_H
#define INVALID_POINTER_H

#include <exception>
#include <string>

namespace exceptions {
class invalid_pointer_exception : public std::exception {
   public:
    invalid_pointer_exception();

    const char* what() const noexcept override;
};
}  // namespace exceptions

#endif