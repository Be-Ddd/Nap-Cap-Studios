
//  GameObject.h
// Demo
//
//  This class represents a basic game object in the world.
//  It can be a player, guard, or other interactive entity.
//
//  Author: Your Name
//  Date: 2/22/26
//
#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include <cugl/cugl.h>


/**
 * A basic game object that can be rendered and updated.
 *
 * This class serves as a base for players, guards, and other entities
 * in the game world. It handles position, rendering, and basic state.
 */
class GameObject {
protected:
    /** The position of this object in world coordinates */
    cugl::Vec2 _position;
    
    /** The velocity of this object (for movement) */
    cugl::Vec2 _velocity;
    
    /** The texture/sprite for rendering this object */
    std::shared_ptr<cugl::graphics::Texture> _texture;
    
    
    /** Whether this object is currently active */
    bool _active;
    
    /** The size/scale of this object */
    cugl::Vec2 _size;
    
    /** The angle/rotation of this object (in radians) */
    float _angle;
    
    /** Unique identifier for this object */
    int _id;

public:
#pragma mark -
#pragma mark Constructors
    /**
     * Creates a new game object at the origin.
     */
    GameObject();
    
    /**
     * Destroys this game object, releasing all resources.
     */
    ~GameObject() { dispose(); }
    
    /**
     * Disposes all resources and assets of this game object.
     */
    void dispose();
    
    /**
     * Initializes a new game object at the given position.
     *
     * @param pos       The initial position
     * @param texture   The texture for rendering
     *
     * @return true if initialization was successful
     */
    bool init(const cugl::Vec2& pos, const std::shared_ptr<cugl::graphics::Texture>& texture);
    
    /**
     * Returns a newly allocated game object at the given position.
     *
     * @param pos       The initial position
     * @param texture   The texture for rendering
     *
     * @return a newly allocated game object
     */
    static std::shared_ptr<GameObject> alloc(const cugl::Vec2& pos,
                                             const std::shared_ptr<cugl::graphics::Texture>& texture) {
        std::shared_ptr<GameObject> result = std::make_shared<GameObject>();
        return (result->init(pos, texture) ? result : nullptr);
    }

#pragma mark -
#pragma mark Accessors
    /**
     * Returns the position of this object.
     *
     * @return the position of this object
     */
    const cugl::Vec2& getPosition() const { return _position; }
    
    /**
     * Sets the position of this object.
     *
     * @param pos   The new position
     */
    void setPosition(const cugl::Vec2& pos);
    
    /**
     * Returns the velocity of this object.
     *
     * @return the velocity of this object
     */
    const cugl::Vec2& getVelocity() const { return _velocity; }
    
    /**
     * Sets the velocity of this object.
     *
     * @param vel   The new velocity
     */
    void setVelocity(const cugl::Vec2& vel) { _velocity = vel; }
    
    /**
     * Returns the angle of this object in radians.
     *
     * @return the angle of this object
     */
    float getAngle() const { return _angle; }
    
    /**
     * Sets the angle of this object in radians.
     *
     * @param angle The new angle
     */
    void setAngle(float angle);
    
    /**
     * Returns whether this object is active.
     *
     * @return whether this object is active
     */
    bool isActive() const { return _active; }
    
    /**
     * Sets whether this object is active.
     *
     * @param active Whether this object is active
     */
    void setActive(bool active) { _active = active; }
    
    
    /**
     * Returns the unique ID of this object.
     *
     * @return the unique ID of this object
     */
    int getID() const { return _id; }
    
    /**
     * Sets the unique ID of this object.
     *
     * @param id    The unique ID
     */
    void setID(int id) { _id = id; }

#pragma mark -
#pragma mark Gameplay
    /**
     * Updates this object's state.
     *
     * @param delta The time in seconds since the last update
     */
    virtual void update(float delta);
    
    /**
     * Draws this object to the sprite batch.
     *
     * @param batch The sprite batch for drawing
     */
    virtual void draw(const std::shared_ptr<cugl::graphics::SpriteBatch>& batch);
};

#endif /* __GAME_OBJECT_H__ */
