class Solution:
    """
    @param: strs: a list of strings
    @return: encodes a list of strings to a single string.
    """
    def encode(self, strs):
        # write your code here
        resString = ""
        for string in strs:
            resString += string + ";;;"
        resString = resString[:-3]
        return resString

    """
    @param: str: A string
    @return: decodes a single string to a list of strings
    """
    def decode(self, str):
        # write your code here
        lst = str.split(";;;")
        return lst