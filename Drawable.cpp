#include "Drawable.h"

using namespace shgame::rendering;


shgame::rendering::Drawable::Drawable()
{
}

Drawable::Drawable(unsigned int edgeCount)
{
	FLOAT_COUNT = edgeCount*3;
	FLOAT_DATA_MEMORY_SIZE = FLOAT_COUNT * sizeof(float);
	
	vertexDataPtr = static_cast<float*>(std::malloc(FLOAT_DATA_MEMORY_SIZE));
	dirty = true;
}

void Drawable::updateVertices()
{

}

void Drawable::draw()
{
	if (!DidSetup)
		setup();
	if (dirty) {
		updateVertices();
		dirty = false;
	}
	bindVAO();
	bindVBO();
	float* ptr = vertexDataPtr;
	for (int i = 0; i < FLOAT_COUNT; i += 9) {
		//glBufferSubData(GL_ARRAY_BUFFER, i * sizeof(float), 9 * sizeof(float), ptr);
		ptr += 9;
	}
	//glDrawArraysInstanced(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	unbindVAO();
	unbindVBO();
}

void Drawable::setup()
{
	//glGenBuffers(1, &vaoHandle);
	//glGenBuffers(1, &vboHandle);

	//glBindVertexArray(vaoHandle);

	//glBindBuffer(GL_ARRAY_BUFFER, vboHandle);
	//glBufferData(GL_ARRAY_BUFFER, FLOAT_DATA_MEMORY_SIZE, nullptr, GL_STATIC_DRAW);

	//glEnableVertexAttribArray(0);
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, FLOAT_DATA_MEMORY_SIZE, nullptr);


	vertexDataPtr = static_cast<float*>(std::malloc(FLOAT_DATA_MEMORY_SIZE));
	dirty = true;
}

void Drawable::dispose()
{
	std::free(vertexDataPtr);
}


inline void Drawable::bindVAO()
{
	//glBindVertexArray(vaoHandle);
}

inline void Drawable::unbindVAO()
{
	//glBindVertexArray(0);
}

inline void Drawable::bindVBO()
{
	//glBindBuffer(GL_ARRAY_BUFFER, vboHandle);
}

inline void Drawable::unbindVBO()
{
	//glBindBuffer(GL_ARRAY_BUFFER, 0);
}