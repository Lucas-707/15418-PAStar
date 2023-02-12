#ifndef INSAT_ACTION_HPP
#define INSAT_ACTION_HPP

#include <common/insat/InsatState.hpp>
#include <common/Action.hpp>

namespace ps
{

    class InsatAction : public Action
    {

    public:
        // Action(){};
        InsatAction(const std::string& type, ParamsType params = ParamsType(), bool is_expensive = true)
                : Action(type, params, is_expensive){};
        virtual ~InsatAction(){};

        virtual TrajType optimize(const StateVarsType& s1, const StateVarsType& s2, int thread_id=0)=0;
        virtual TrajType warmOptimize(const TrajType& t1, const TrajType& t2, int thread_id=0)=0;
        virtual double getCost(const TrajType& traj, int thread_id=0)=0;
        virtual bool isFeasible(TrajType& traj)=0;

    protected:
        std::string type_;
        ParamsType params_;
        bool is_expensive_;

    };

}

#endif