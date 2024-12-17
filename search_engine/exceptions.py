class UrlError(ValueError):
    """
    Exception raised when an invalid URL is provided.

    Inherits from the built-in `ValueError` class.

    Attributes
    ----------
    message : str
        The error message that describes the cause of the exception.
        Defaults to "Invalid URL".

    Methods
    -------
    __init__(self, message: str = "Invalid URL")
        Initializes the exception with a custom message or a default message.
    """

    def __init__(self, message="Invalid URL"):
        """
        Initializes the UrlError exception with a custom error message.

        Parameters
        ----------
        message : str, optional
            The error message to describe the exception. Default is "Invalid URL".
        """
        self.message = message
        super().__init__(self.message)
