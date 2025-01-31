#ifndef INVALID_POINTER_H
#define INVALID_POINTER_H

#include <exception>
#include <string>

namespace exceptions {

/**
 * @class invalid_pointer_exception
 * @brief Exception indicating the use of an invalid pointer.
 *
 * This exception is derived from `std::exception` and can be thrown
 * when an invalid pointer is detected.
 */
class invalid_pointer_exception : public std::exception {
   public:
    /**
     * @brief Constructor for the invalid_pointer_exception class.
     *
     * Initializes a new instance of the exception.
     */
    invalid_pointer_exception();

    /**
     * @brief Returns a descriptive error message.
     *
     * @return A C-style string describing the error.
     */
    const char* what() const noexcept override;
};

}  // namespace exceptions

#endif  // INVALID_POINTER_H
