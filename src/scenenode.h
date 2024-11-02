#ifndef SRC_SCENENODE_H_
#define SRC_SCENENODE_H_

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable {

 public: 
    typedef std::unique_ptr<SceneNode> Ptr;
 public:
    SceneNode();
    void  attachChild(Ptr child);
    Ptr   detachChild(const SceneNode& node);

 private:
    std::vector<Ptr> mChildren;
    SceneNode* mParent;

};
#endif