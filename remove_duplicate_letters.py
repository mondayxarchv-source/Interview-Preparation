def remove_duplicate_letters(text: str) -> str:
    from collections import Counter

    remaining = Counter(text)   # frequency of characters left
    result_stack = []
    used_chars = set()

    for letter in text:
        remaining[letter] -= 1

        # skip if already added
        if letter in used_chars:
            continue

        # maintain lexicographical order
        while (
            result_stack and
            result_stack[-1] > letter and
            remaining[result_stack[-1]] > 0
        ):
            removed_char = result_stack.pop()
            used_chars.remove(removed_char)

        result_stack.append(letter)
        used_chars.add(letter)

    return "".join(result_stack)
