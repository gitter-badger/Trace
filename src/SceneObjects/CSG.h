#ifndef CSG_H
#define CSG_H

#include "../scene/scene.h"
#include <vector>

enum CSG_RELATION {
	CSG_OR = 1,
	CSG_AND,
	CSG_MINUS
};

struct SegmentPoint {
	double t;
	vec3f nomral;
	bool isRight;
	int contri;
};

class Segments 
{
public:
	Segments& Merge(const Segments& another, int relation);

private:
	vector<SegmentPoint> points;
};

class CSGNode 
{
public:
	CSGNode() :lchild(NULL), rchild(NULL), item(NULL), relation(AND), isLeaf(0){};
	CSGNode *lchild, *rchild;
	Geometry* item;
	CSG_RELATION relation;
	bool isLeaf;
};

class CSGTree
{
public:
	CSGTree() : root(NULL) {}
	CSGTree(Geometry* obj, CSGNode* ptr){
		root = ptr;
		root->item = obj;
		root->isLeaf = true;
	}
	CSGTree& Merge(const CSGTree& pB, int relation);
	bool intersect(const ray& r, isect& i) const;
private:
	CSGNode* root;
	Segments& intersectLocal(const ray& r) const;
};

class CSG : public MaterialSceneObject
{
public:
	CSG(Scene *scene, Material *mat) : MaterialSceneObject(scene, mat) {}
	virtual bool intersectLocal(const ray& r, isect& i) const;
	virtual bool hasBoundingBoxCapability() const { return true; }
	virtual bool hasInterior() const{ return true; }
	virtual BoundingBox ComputeLocalBoundingBox();
private:
	CSGTree tree;
};

#endif