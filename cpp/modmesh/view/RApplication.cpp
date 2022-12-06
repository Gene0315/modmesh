/*
 * Copyright (c) 2022, Yung-Yu Chen <yyc@solvcon.net>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the name of the copyright holder nor the names of its contributors
 *   may be used to endorse or promote products derived from this software
 *   without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <modmesh/view/RApplication.hpp> // Must be the first include.

#include <modmesh/view/RMainWindow.hpp>

#include <vector>

#include <QActionGroup>

namespace modmesh
{

RApplication * RApplication::initialize(int & argc, char ** argv)
{
    RApplication * ret = dynamic_cast<RApplication *>(QApplication::instance());
    if (nullptr == ret)
    {
        // Be very careful that QApplication (where RApplication inherits from)
        // needs int& argc!!
        ret = new RApplication(argc, argv);
    }
    return ret;
}

RApplication * RApplication::instance()
{
    RApplication * ret = dynamic_cast<RApplication *>(QApplication::instance());
    static int argc = 1;
    static char exename[] = "viewer";
    static char * argv[] = {exename};
    if (nullptr == ret)
    {
        ret = initialize(argc, argv);
    }
    return ret;
}

RApplication & RApplication::setUp()
{
    if (nullptr != m_mainWindow)
    {
        m_mainWindow->setUp();
    }
    return *this;
}

RApplication::RApplication(int & argc, char ** argv)
    : QApplication(argc, argv)
    , m_mainWindow(new RMainWindow)
{
}

RApplication::~RApplication()
{
}

R3DWidget * RApplication::add3DWidget()
{
    R3DWidget * viewer = nullptr;
    if (m_mainWindow)
    {
        viewer = new R3DWidget();
        viewer->setWindowTitle("3D viewer");
        viewer->show();
        auto * subwin = m_mainWindow->addSubWindow(viewer);
        subwin->resize(300, 200);
    }
    return viewer;
}

} /* end namespace modmesh */

// vim: set ff=unix fenc=utf8 et sw=4 ts=4 sts=4:
