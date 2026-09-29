void energy(int n, std::vector<int> v)
{
    if (n == 2)
    {
        int d = std::abs(v[0] - v[1]);
        int e = std::min(d, 50000 - d);

        if (e == 25000)
            return;

        int target = (v[1] + 25000) % 50000;
        int delta = (target - v[0] + 50000) % 50000;
        rotate({0}, delta);
    }

    std::vector<std::pair<int, int>> sorted;
    for (int i = 0; i < n; i++)
        sorted.push_back({v[i], i});
    std::sort(sorted.begin(), sorted.end());

    auto total_efficiency = [&]()
    {
        long long sum = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                sum += circular_dist(v[i], v[j]);
        return sum;
    };

    long long cur_eff = total_efficiency();

    std::vector<int> half_indices;
    for (int i = n / 2; i < n; i++)
        half_indices.push_back(sorted[i].second);

    std::vector<int> v_copy = v;
    for (int idx : half_indices)
        v_copy[idx] = (v_copy[idx] + 25000) % 50000;
    long long effA = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            effA += circular_dist(v_copy[i], v_copy[j]);

    std::vector<int> half_indices2;
    for (int i = 0; i < n / 2; i++)
        half_indices2.push_back(sorted[i].second);
    std::vector<int> v_copy2 = v;
    for (int idx : half_indices2)
        v_copy2[idx] = (v_copy2[idx] + 25000) % 50000;
    long long effB = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            effB += circular_dist(v_copy2[i], v_copy2[j]);

    if (effA >= cur_eff && effA >= effB)
    {
        rotate(half_indices, 25000);
    }
    else if (effB >= cur_eff)
    {
        rotate(half_indices2, 25000);
    }
}