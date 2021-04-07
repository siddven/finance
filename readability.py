from cs50 import get_string

def main():
    text = get_string("Text:")
    average_letter = 100/word(text)
    L = letter(text) * average_letter
    S = sentence(text) * average_letter
    index = 0.0588 * L - 0.296 * S - 15.8
    diff = index - int(index)
    add = 1 - diff
    if diff < 0.5:
        index -= diff
    if diff >= 0.5:
        index += add

    if index < 1:
        print("Before Grade 1")

    if index > 16:
        print("Grade 16+")

    if index > 1 and index <= 16:
        print("Grade",int(index))


def letter(text):
    letters = 0.0
    text = text.upper()
    for i in range(len(text)):
        if ord(text[i]) >= 65 and ord(text[i]) <= 90:
            letters += 1
    return letters

def word(text):
    words = 0.0
    for i in range(len(text)):
        if ord(text[i]) == 32:
            words += 1
    return words

def sentence(text):
    sentences = 0.0
    for i in range(len(text)):
        if ord(text[i]) == 33 or ord(text[i]) == 63 or ord(text[i]) == 46:
            sentences += 1

    return sentences


main()
