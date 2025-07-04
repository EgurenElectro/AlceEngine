#pragma once

#include "../../Modules/Modules.hpp"

namespace alce
{
    enum BodyType
    {
        static_body,
        dynamic_body,
        kinematic_body,
        none_body
    };

    class Rigidbody2D : public Component
    {
    public:

        Rigidbody2D();

        ~Rigidbody2D();

        void CreateBody(ShapePtr shape, BodyType bodyType = BodyType::dynamic_body, bool fixedRotation = false, MaskType maskType = MaskType::mask_1);

        void DestroyBody();

        float GetDensity();

        void SetDensity(float density);

        float GetFriction();

        void SetFriction(float friction);

        float GetRestitution();

        void SetRestitution(float restitution);

        float GetRestitutionThreshold();

        void SetRestitutionThreshold(float restitutionThreshold);

        void ApplyForce(Vector2 force, bool wake = true);

        void ApplyLinearForce(Vector2 force, bool wake = true);

        void SetLinearVelocity(Vector2 linearVelocity);

        Vector2 GetLinearVelocity();

        void SetVerticalVelocity(float vy);

        void SetHorizontalVelocity(float vx);

        void SetAngularVelocity(float va);

        void SetAngularDamping(float ad);

        void SetLinearDamping(float ld);

        void ApplyAngularImpulse(float impulse);

        void ApplyTorque(float torque, bool wake = true);

        float GetAngle();

        void SetAngle(float angle);

        float GetInertia();

        float GetGravityScale();

        BodyType GetBodyType();

        void SetBodyType(BodyType bodyType);

        ShapeType GetShapeType();

        void SetPosition(Vector2 position, bool awake = true);

        void SetPosition(float x, float y, bool awake = true);

        void SetRotation(float rotation, bool awake = true);

        Vector2 GetPosition();

        void SetFixedRotation(bool flag = true);

        void DebugRender();

        void Init();

        void Start();

        void Update();

        void SetTag(String tag);

        String GetTag();

        bool HasBody()
        {
            return body != nullptr;
        }

    private:

        friend class GameObject;

        float density = 10.0f;
        float friction = 1.0f;
        float restitution = 0.0f;
        float restitutionThreshold = 0.0f;

        BodyType bodyType;
        float radius = 0;

        b2Body* body = nullptr;
        b2Fixture* fixture;
        ContactListenerPtr contactListener;
        B2WorldPtr world = nullptr;

        ShapePtr shape = nullptr;
        Vector2 shapePos;
    };

    typedef std::shared_ptr<Rigidbody2D> Rigidbody2DPtr;
}