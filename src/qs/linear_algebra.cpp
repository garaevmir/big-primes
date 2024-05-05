#include "quadratic_sieve.h"


namespace project {

    std::vector<std::vector<SmallType>> QuadraticSieve::gaussian_elimination(const std::vector<std::vector<SmallType>>& matrix) {
        std::vector<std::vector<SmallType>> matrix_mod = matrix;
        IndexType n = matrix_mod.size();
        assert(n > 0);
        IndexType m = matrix_mod[0].size();
        for (IndexType i = 0; i < n; ++i) {
            for (IndexType j = 0; j < m; ++j) {
                matrix_mod[i][j] %= 2;
            }
        }
        IndexType shift = 0;
        std::vector<std::vector<SmallType>> used(n, std::vector<SmallType>(n, 0));
        for (IndexType i = 0; i < n; ++i) {
            used[i][i] = 1;
        }
        for (IndexType i = 0; i < m; ++i) {
            IndexType index = i - shift;
            if (index >= n) {
                break;
            }
            IndexType temp = index;
            for (IndexType j = index; j < n; ++j) {
                if (matrix_mod[j][i] == 1) {
                    temp = j;
                    break;
                }
            }
            if (temp == index && matrix_mod[index][i] != 1) {
                ++shift;
                continue;
            }
            std::swap(matrix_mod[index], matrix_mod[temp]);
            std::swap(used[index], used[temp]);
            for (IndexType j = index + 1; j < n; ++j) {
                if (matrix_mod[j][i] == 1) {
                    for (IndexType l = 0; l < n; ++l) {
                        used[j][l] = (used[j][l] + used[index][l]) % 2;
                    }
                    for (IndexType l = i; l < m; ++l) {
                        matrix_mod[j][l] = (matrix_mod[j][l] + matrix_mod[index][l]) % 2;
                    }
                }
            }
        }
        std::vector<std::vector<SmallType>> use(used.begin() + (std::min(n, m) > shift ? std::min(n, m) - shift : IndexType (0)), used.end());
        return use;
    }
}
