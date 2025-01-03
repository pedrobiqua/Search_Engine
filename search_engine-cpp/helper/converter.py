class StringToIntConverter:
    """
    A class that converts strings to integers. If a string has already been converted,
    it returns the previously assigned integer. Otherwise, it assigns a new integer
    to the string and returns it.

    Attributes
    ----------
    string_to_int : dict
        A dictionary mapping strings to their corresponding integers.
    next_int : int
        The next integer to be assigned to a string.

    Methods
    -------
    __init__()
        Initializes the converter with an empty dictionary and sets the next integer to 0.
    convert(word: str) -> int
        Converts a given string to an integer. If the string has been seen before,
        it returns the corresponding integer, otherwise it assigns a new integer to the string.
    """

    def __init__(self):
        """
        Initializes the StringToIntConverter with an empty dictionary and sets the next integer
        to 0 for string-to-integer mapping.

        Attributes
        ----------
        string_to_int : dict
            An empty dictionary to store the mapping of strings to integers.
        next_int : int
            Initialized to 0, it represents the next available integer to be assigned to a string.
        """
        self.string_to_int = {}
        self.next_int = 0

    def convert(self, word: str) -> int:
        """
        Convert a string to an integer. If the string has already been seen,
        return its corresponding integer. Otherwise, assign a new integer to it.

        Parameters
        ----------
        word : str
            The string to be converted.

        Returns
        -------
        int
            The integer corresponding to the string.
        """
        if word not in self.string_to_int:
            self.string_to_int[word] = self.next_int
            self.next_int += 1
        return self.string_to_int[word]
