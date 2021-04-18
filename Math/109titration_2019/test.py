import unittest
from 109titration import *

class TestNum(unittest.TestCase):
    def test_res(self):
        self.assertEqual(3, main(values.csv))

unittest.main()