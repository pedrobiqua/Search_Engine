class StringToIntConverter:
    def __init__(self):
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