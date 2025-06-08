#pragma once
using namespace std;

namespace shgame::rendering	
{

	class Drawable
	{
		protected:
			unsigned int vaoHandle = 0;
			unsigned int vboHandle = 0;

			unsigned int  VERTICES_COUNT;

		public:
			float* vertexDataPtr;
			bool dirty = true;

			void bindVBO();
			void unbindVBO();

			void bindVAO();
			void unbindVAO();
			
			Drawable();

			Drawable(unsigned int verticesCount);
			
			void setup();

			virtual void dispose();

			void draw();

			static float* bufferTriangleValues();

		private:
			bool DidSetup = false;
	};
}