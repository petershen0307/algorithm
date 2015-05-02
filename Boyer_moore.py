def search_string(test_sting, pattern_string):
    boyer_moore_table = create_boyer_moore_table(pattern_string)
    PATTERN_STRING_LENGET = len(pattern_string)
    test_index = PATTERN_STRING_LENGET - 1
    pattern_index = PATTERN_STRING_LENGET - 1
    is_found = False
    while 0 < test_index < len(test_sting):
        if pattern_string[pattern_index] == test_sting[test_index]:
            if pattern_index == 0:
                is_found = True
                break
            test_index -= 1
            pattern_index -= 1
        else:
            test_index += (PATTERN_STRING_LENGET - 1 - pattern_index)
            if test_sting[test_index] in boyer_moore_table:
                test_index += boyer_moore_table[test_sting[test_index]]
            else:
                test_index += boyer_moore_table['*']
            pattern_index = PATTERN_STRING_LENGET - 1
    if is_found:
        return {'position': test_index}
    return {'position': -1}


def create_boyer_moore_table(pattern):
    boyer_moore_table = dict()
    pattern_index = 0
    for char in pattern:
        boyer_moore_table[char] = max(1, len(pattern) - 1 - pattern_index)
        pattern_index += 1
    boyer_moore_table['*'] = len(pattern)
    return boyer_moore_table

if __name__ == '__main__':
    print(create_boyer_moore_table('bc'))
    print(search_string('abcde', 'bcd'))