import pyperclip

def ascii_to_array(ascii_art):
    result = []
    for line in ascii_art.splitlines():
        row = [ord(char) for char in line]
        result.append(row)
    return result


def main():
    ascii_art = pyperclip.paste()
    array = ascii_to_array(ascii_art)

    for row in array:
        print(" ".join(map(str, row)))

if __name__ == "__main__":
    main()
