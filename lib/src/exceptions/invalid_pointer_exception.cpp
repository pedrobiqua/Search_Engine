#include "exceptions/invalid_pointer_exception.h"

namespace exceptions {

// Definição do construtor com mensagem padrão
invalid_pointer_exception::invalid_pointer_exception() {}

// Definição do método what(), retornando a mensagem padrão
const char* invalid_pointer_exception::what() const noexcept {
    return "Invalid pointer exception occurred.";
}

}  // namespace exceptions
