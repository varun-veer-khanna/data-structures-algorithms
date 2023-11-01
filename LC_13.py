# not done on my own yet
class Solution:
    def romanToInt(self, s: str) -> int:
        translations = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }
        sum = 0

        for (i = s.length() - 2; i >= 0; --i):
            if (translations[s[i]] < translations[s[i + 1]]):
                sum -= translations[s[i]]
            else:
                sum += translations[s[i]]

        print(sum)

string="MCMXCIV"
obj1=Solution()
obj1.romanToInt(string)