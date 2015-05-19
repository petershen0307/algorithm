def search_string(test_sting, pattern_string):
    boyer_moore_table = create_boyer_moore_table(pattern_string)
    PATTERN_STRING_LENGET = len(pattern_string)
    test_index = PATTERN_STRING_LENGET - 1
    pattern_index = PATTERN_STRING_LENGET - 1
    result = {'found_position': [], 'found_count': 0}
    while 0 <= test_index < len(test_sting):
        if pattern_string[pattern_index] == test_sting[test_index]:
            if pattern_index == 0:
                result['found_position'].append(test_index)
                result['found_count'] += 1
                test_index += PATTERN_STRING_LENGET
                pattern_index = PATTERN_STRING_LENGET - 1
                continue
            test_index -= 1
            pattern_index -= 1
        else:
            test_index += (PATTERN_STRING_LENGET - 1 - pattern_index)
            if test_sting[test_index] in boyer_moore_table:
                test_index += boyer_moore_table[test_sting[test_index]]
            else:
                test_index += boyer_moore_table['*']
            pattern_index = PATTERN_STRING_LENGET - 1

    return result


def create_boyer_moore_table(pattern):
    boyer_moore_table = dict()
    pattern_index = 0
    for char in pattern:
        boyer_moore_table[char] = max(1, len(pattern) - 1 - pattern_index)
        pattern_index += 1
    boyer_moore_table['*'] = len(pattern)
    return boyer_moore_table


def get_line_number(source_string):
    string_list = source_string.split('\n')
    return len(string_list)

if __name__ == '__main__':
    print(create_boyer_moore_table('abcd'))
    rr = search_string('aabbcceebb', 'bb')
    print(rr['found_position'])