/* ========================================================================= *
 *                                                                           *
 *                               OpenMesh                                    *
 *           Copyright (c) 2001-2015, RWTH-Aachen University                 *
 *           Department of Computer Graphics and Multimedia                  *
 *                          All rights reserved.                             *
 *                            www.openmesh.org                               *
 *                                                                           *
 *---------------------------------------------------------------------------*
 * This file is part of OpenMesh.                                            *
 *---------------------------------------------------------------------------*
 *                                                                           *
 * Redistribution and use in source and binary forms, with or without        *
 * modification, are permitted provided that the following conditions        *
 * are met:                                                                  *
 *                                                                           *
 * 1. Redistributions of source code must retain the above copyright notice, *
 *    this list of conditions and the following disclaimer.                  *
 *                                                                           *
 * 2. Redistributions in binary form must reproduce the above copyright      *
 *    notice, this list of conditions and the following disclaimer in the    *
 *    documentation and/or other materials provided with the distribution.   *
 *                                                                           *
 * 3. Neither the name of the copyright holder nor the names of its          *
 *    contributors may be used to endorse or promote products derived from   *
 *    this software without specific prior written permission.               *
 *                                                                           *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS       *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED *
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A           *
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER *
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  *
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,       *
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR        *
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF    *
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING      *
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS        *
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.              *
 *                                                                           *
 * ========================================================================= */

//TODO: for house base floor plan
//generate original rectangle
//generate up to 2 more rectangles
//each generated rectangle will have a randomly generated point inside it
//this point will be where the center of the original rectangle overlaps
//so far, this will be 3 separate vectors of 4 vertexes
//now we will combine it into one vector
//first add all vertexes that are not interior, as in not inside another rectangle
//then compute intersection of rectangle edges and add those as vertexes.
//furthermore, we should generate rectangles with integer coordinates so that snapping is possible
// and there aren't very small protrusions which are impractical.

#ifdef _MSC_VER
#  pragma warning(disable: 4267 4311)
#endif

#include <iostream>
#include <fstream>
#include <QApplication>
#include <QMessageBox>
#include <QMainWindow>
#include <QMenuBar>
#include <QFileDialog>

#include "MeshViewerWidget.hh"


void create_menu(QMainWindow &w);
void usage_and_exit(int xcode);

int main(int argc, char **argv)
{

  //copied from tut1
  MyMesh mesh;
  // generate vertices
  MyMesh::VertexHandle vhandle[8];
  vhandle[0] = mesh.add_vertex(MyMesh::Point(-1, -1,  1));
  vhandle[1] = mesh.add_vertex(MyMesh::Point( 1, -1,  1));
  vhandle[2] = mesh.add_vertex(MyMesh::Point( 1,  1,  1));
  vhandle[3] = mesh.add_vertex(MyMesh::Point(-1,  1,  1));
  vhandle[4] = mesh.add_vertex(MyMesh::Point(-1, -1, -1));
  vhandle[5] = mesh.add_vertex(MyMesh::Point( 1, -1, -1));
  vhandle[6] = mesh.add_vertex(MyMesh::Point( 1,  1, -1));
  vhandle[7] = mesh.add_vertex(MyMesh::Point(-1,  1, -1));
  // generate (quadrilateral) faces
  std::vector<MyMesh::VertexHandle>  face_vhandles;
  face_vhandles.clear();
  face_vhandles.push_back(vhandle[0]);
  face_vhandles.push_back(vhandle[1]);
  face_vhandles.push_back(vhandle[2]);
  face_vhandles.push_back(vhandle[3]);
  mesh.add_face(face_vhandles);
 
  face_vhandles.clear();
  face_vhandles.push_back(vhandle[7]);
  face_vhandles.push_back(vhandle[6]);
  face_vhandles.push_back(vhandle[5]);
  face_vhandles.push_back(vhandle[4]);
  mesh.add_face(face_vhandles);
  face_vhandles.clear();
  face_vhandles.push_back(vhandle[1]);
  face_vhandles.push_back(vhandle[0]);
  face_vhandles.push_back(vhandle[4]);
  face_vhandles.push_back(vhandle[5]);
  mesh.add_face(face_vhandles);
  face_vhandles.clear();
  face_vhandles.push_back(vhandle[2]);
  face_vhandles.push_back(vhandle[1]);
  face_vhandles.push_back(vhandle[5]);
  face_vhandles.push_back(vhandle[6]);
  mesh.add_face(face_vhandles);
  face_vhandles.clear();
  face_vhandles.push_back(vhandle[3]);
  face_vhandles.push_back(vhandle[2]);
  face_vhandles.push_back(vhandle[6]);
  face_vhandles.push_back(vhandle[7]);
  mesh.add_face(face_vhandles);
  face_vhandles.clear();
  face_vhandles.push_back(vhandle[0]);
  face_vhandles.push_back(vhandle[3]);
  face_vhandles.push_back(vhandle[7]);
  face_vhandles.push_back(vhandle[4]);
  mesh.add_face(face_vhandles);
  //end tut1 copy

  // OpenGL check
  QApplication::setColorSpec( QApplication::CustomColor );
  QApplication app(argc,argv);

  if ( !QGLFormat::hasOpenGL() ) {
    QString msg = "System has no OpenGL support!";
    QMessageBox::critical( 0, QString("OpenGL"), msg + QString(argv[1]) );
    return -1;
  }

  int c;
  OpenMesh::IO::Options opt;

  while ( (c=getopt(argc,argv,"hbs"))!=-1 )
  {
     switch(c)
     {
       case 'b': opt += OpenMesh::IO::Options::Binary; break;
       case 'h':
          usage_and_exit(0);
          break;
       case 's': opt += OpenMesh::IO::Options::Swap; break;
       default:
          usage_and_exit(1);
     }
  }

  // enable most options for now
  opt += OpenMesh::IO::Options::VertexColor;
  opt += OpenMesh::IO::Options::VertexNormal;
  opt += OpenMesh::IO::Options::VertexTexCoord;
  opt += OpenMesh::IO::Options::FaceColor;
  opt += OpenMesh::IO::Options::FaceNormal;
  opt += OpenMesh::IO::Options::FaceTexCoord;

  // create widget
  QMainWindow mainWin;
  MeshViewerWidget w(&mainWin);
  w.setOptions(opt);
  mainWin.setCentralWidget(&w);

  create_menu(mainWin);

  // static mesh, hence use strips
  w.enable_strips();

  mainWin.resize(640, 480);
  mainWin.show();

  // load scene if specified on the command line
  if ( optind < argc )
  {
    w.open_mesh_gui(argv[optind]);
  }

  if ( ++optind < argc )
  {
      w.open_texture_gui(argv[optind]);
  }

  return app.exec();
}

void create_menu(QMainWindow &w)
{
    using namespace Qt;
    QMenu *fileMenu = w.menuBar()->addMenu(w.tr("&File"));

    QAction* openAct = new QAction(w.tr("&Open mesh..."), &w);
    openAct->setShortcut(w.tr("Ctrl+O"));
    openAct->setStatusTip(w.tr("Open a mesh file"));
    QObject::connect(openAct, SIGNAL(triggered()), w.centralWidget(), SLOT(query_open_mesh_file()));
    fileMenu->addAction(openAct);

    QAction* texAct = new QAction(w.tr("Open &texture..."), &w);
    texAct->setShortcut(w.tr("Ctrl+T"));
    texAct->setStatusTip(w.tr("Open a texture file"));
    QObject::connect(texAct, SIGNAL(triggered()), w.centralWidget(), SLOT(query_open_texture_file()));
    fileMenu->addAction(texAct);
}

void usage_and_exit(int xcode)
{
   std::cout << "Usage: meshviewer [-s] [mesh] [texture]\n" << std::endl;
   std::cout << "Options:\n"
	     << "  -b\n"
	     << "    Assume input to be binary.\n\n"
             << "  -s\n"
             << "    Reverse byte order, when reading binary files.\n"
             << std::endl;
   exit(xcode);
}
