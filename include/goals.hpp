#pragma once

enum class goals {
	none        = 0,
	divergence  = 1,
	generation  = 2
};

inline goals operator|(const goals & a, const goals & b) {
    return (goals) ((int)a | (int)b);
}

inline goals operator&(const goals &a, const goals &b) {
    return (goals) ((int)a & (int)b);
}


