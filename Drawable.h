#pragma once
#include <cstdlib>

#ifndef __glad_h_
	#include "glad.h"
#endif // !__glad_h_


using namespace std;

namespace shgame::rendering	
{

	class Drawable
	{
		protected:
			GLuint vaoHandle;
			GLuint vboHandle;

			unsigned int FLOAT_COUNT;
			unsigned int FLOAT_DATA_MEMORY_SIZE;

		public:
			float* vertexDataPtr;
			bool dirty = true;

			Drawable();

			Drawable(unsigned int verticesCount);
			
			void bindVBO();
			void unbindVBO();

			void bindVAO();
			void unbindVAO();
			
			
			void setup();
			void dispose();

			virtual void updateVertices();
			void draw();

			static float* bufferTriangleValues();

		private:
			bool DidSetup = false;
	};
}