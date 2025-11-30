def Difficulty(s) :
    if s is None or s.strip() == "":
        return 0
    vowels = set('aeiou')
    def count_vowels_and_consonants(word):
        vowel_count = sum(1 for char in word if char in vowels)
        consonant_count = len(word) - vowel_count
        return vowel_count, consonant_count

    def has_three_consonants(word):
        count = 0
        for char in word:
            if char in vowels:
                count = 0
            else:
                count += 1
                if count >= 3:
                    return True
        return False

    words = s.split()
    hard_c = 0
    easy_c = 0
    for word in words:
        vowel_count, consonant_count = count_vowels_and_consonants(word)
        if consonant_count > vowel_count or has_three_consonants(word):
            hard_c += 1
        else:
            easy_c += 1

    difficulty = (5 * hard_c) - (2 * easy_c)
    return difficulty


input_str = "qiewldoaa life ace by fantasy"
print(Difficulty(input_str)) 