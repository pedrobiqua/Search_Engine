class UrlError(ValueError):
    """Raised when an invalid URL is provided."""
    def __init__(self, message="Invalid URL"):
        self.message = message
        super().__init__(self.message)