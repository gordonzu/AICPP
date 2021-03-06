// gordon zuehlke on 8/27/18

#include "agent.h"
//#include "environment/environment.h"

Agent::Agent() : ap{nullptr} {
    hashval = hash_it();
} 

Agent::Agent(AgentProgram* program): ap{program} {
    hashval = hash_it();
}

Agent::~Agent() {
}

bool Agent::set_program(AgentProgram* program) {
    if (program) {
        ap = program;
        return true;
    }
    return false;
}

bool Agent::program_state() const {
    if (ap == nullptr) return true;
    return false;
}

Action Agent::execute(const Percept& per) const {
    if (ap != nullptr) {
        Action tmp = ap->execute(per);
        bool c = tmp.is_no_op();
        return tmp;
    }
    return Action{};
}

Action Agent::the_test(const Percept& per) const {
    if (ap != nullptr) {
        std::cout << "ap is not null" << std::endl;
        Action tmp = ap->execute(per);
        //bool c = tmp.is_no_op();
        //return tmp;
    }
    return Action{};
}

bool Agent::is_wall() const {
    return iswall;
}

bool Agent::is_alive() const {
    return alive;
}

bool Agent::operator==(const Agent& x) const {
    return hashval == x.hashval; 
}

size_t Agent::hash_it() {
    hashval = reinterpret_cast<uint64_t>(this);
    return hashval;
}

std::ostream& operator<<(std::ostream& out, const Agent& x) {
    out << "agent:" << x.hashval << " isWall=" << std::boolalpha << x.iswall;
    return out;
}

