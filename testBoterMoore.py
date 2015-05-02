import unittest
import Boyer_moore


class TestBoyerMoore(unittest.TestCase):
    '''def test_string(self):
        self.assertEqual(Boyer_moore.search_string('abcdefg', 'abc'),
                         {'first_appear': 0, 'count': 1})'''


class TestBoyerMooreTable(unittest.TestCase):
    def test_boyer_moore_table(self):
        self.assertEqual(Boyer_moore.create_boyer_moore_table('asd'),
            {'a': 2, 's': 1, 'd': 1, '*': 3})
        self.assertEqual(Boyer_moore.create_boyer_moore_table('asdsdd'),
            {'a': 5, 's': 2, 'd': 1, '*': 6})
        self.assertEqual(Boyer_moore.create_boyer_moore_table('asdsddfg'),
            {'a': 7, 's': 4, 'd': 2, 'f': 1, 'g': 1, '*': 8})


if __name__ == '__main__':
    unittest.main()
