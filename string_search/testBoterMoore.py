import unittest
import Boyer_moore


class TestBoyerMoore(unittest.TestCase):
    def test_string_single_line(self):
        self.assertEqual(Boyer_moore.search_string('abcdefg', 'abc'),
                         {'found_position': [0], 'found_count': 1})
        self.assertEqual(Boyer_moore.search_string('abcdefgabcghhbc', 'abc'),
                         {'found_position': [0, 7], 'found_count': 2})
        self.assertEqual(Boyer_moore.search_string('aabbcc', 'aa'),
                         {'found_position': [0], 'found_count': 1})
        self.assertEqual(Boyer_moore.search_string('aabbccee', 'bb'),
                         {'found_position': [2], 'found_count': 1})

    def test_string_multiple_lines(self):
        self.assertEqual(Boyer_moore.search_string('tyuiop\n\rabmtyukll\n\rvvvtyu', 'tyu'),
                         {'found_position': [0, 11, 22], 'found_count': 3})

    def test_open_file(self):
        with open('test_files/qaz.txt', encoding='utf-8') as file_content:
            self.assertEqual(Boyer_moore.search_string(file_content.read(), 'qaz'),
                             {'found_position': [0, 22, 32], 'found_count': 3})


class TestBoyerMooreTable(unittest.TestCase):
    def test_boyer_moore_table(self):
        self.assertEqual(Boyer_moore.create_boyer_moore_table('asd'),
                         {'a': 2, 's': 1, 'd': 1, '*': 3})
        self.assertEqual(Boyer_moore.create_boyer_moore_table('asdsdd'),
                         {'a': 5, 's': 2, 'd': 1, '*': 6})
        self.assertEqual(Boyer_moore.create_boyer_moore_table('asdsddfg'),
                         {'a': 7, 's': 4, 'd': 2, 'f': 1, 'g': 1, '*': 8})


class TestGetLineNumber(unittest.TestCase):
    def test_line_number(self):
        self.assertEqual(Boyer_moore.get_line_number('aaa'), 1)
        self.assertEqual(Boyer_moore.get_line_number('aaa\n'), 2)
        self.assertEqual(Boyer_moore.get_line_number('\n'), 2)
        self.assertEqual(Boyer_moore.get_line_number('\njjj'), 2)
        self.assertEqual(Boyer_moore.get_line_number('\njjj\n'), 3)

    def test_open_file(self):
        with open('test_files/line6.txt', encoding='utf-8') as file_content:
            self.assertEqual(Boyer_moore.get_line_number(file_content.read()), 6)


if __name__ == '__main__':
    unittest.main()
