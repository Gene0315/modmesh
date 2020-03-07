# Copyright (c) 2019, Yung-Yu Chen <yyc@solvcon.net>
# BSD-style license; see COPYING


import unittest

import modmesh


class StaticGridTC(unittest.TestCase):

    def test_ndim(self):

        self.assertEqual(1, modmesh.StaticGrid1d.NDIM)
        self.assertEqual(2, modmesh.StaticGrid2d.NDIM)
        self.assertEqual(3, modmesh.StaticGrid3d.NDIM)

# vim: set ff=unix fenc=utf8 et sw=4 ts=4 sts=4: