/*
& f(n) = g(n) + h(n) : g(n) -> start node to current node
& optimal and complete if heuristic is admissible(never overestimating : h(n) <= h*(n) for all nodes: h(n) - heuristic estimate, h*() - actual cost) and consistent
& h(n) : gready bfs g(n) : ucs
& open list (priority queue) and closed list
*/