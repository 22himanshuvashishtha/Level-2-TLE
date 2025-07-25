#include <iostream>
#include <vector>
#include <algorithm>

const int MAX_VAL = 100100; // Max input is 10^5, next prime is 100003
bool is_prime_sieve[MAX_VAL];
int next_prime_arr[MAX_VAL];

// Pre-computes primes and the "next prime" for every number up to MAX_VAL
void precompute_primes() {
    // 1. Sieve of Eratosthenes to find all primes up to MAX_VAL
    std::fill(is_prime_sieve, is_prime_sieve + MAX_VAL, true);
    is_prime_sieve[0] = is_prime_sieve[1] = false;
    for (int p = 2; p * p < MAX_VAL; ++p) {
        if (is_prime_sieve[p]) {
            for (int i = p * p; i < MAX_VAL; i += p) {
                is_prime_sieve[i] = false;
            }
        }
    }

    // 2. Create an array to quickly find the next prime for any number
    int last_known_prime = MAX_VAL - 1;
    // Find the largest prime in our range to start from
    while (!is_prime_sieve[last_known_prime]) {
        last_known_prime--;
    }
    
    // Iterate backwards to fill the next_prime_arr
    for (int i = MAX_VAL - 1; i >= 0; --i) {
        if (is_prime_sieve[i]) {
            last_known_prime = i;
        }
        next_prime_arr[i] = last_known_prime;
    }
}

int main() {
    // Use fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Step 1: Pre-computation as discussed.
    precompute_primes();

    int n, m;
    std::cin >> n >> m;

    // Read the matrix into a 2D vector
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    // Step 2: Calculate the moves needed for each individual cell
    // and store the cost for each row and column.
    std::vector<int> row_moves(n, 0);
    std::vector<int> col_moves(m, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int current_val = matrix[i][j];
            // Find the next prime using our pre-computed array
            int next_p = next_prime_arr[current_val];
            // Calculate moves for this cell
            int moves_needed = next_p - current_val;

            // Add these moves to the total for its row and column
            row_moves[i] += moves_needed;
            col_moves[j] += moves_needed;
        }
    }

    // Step 3: Find the minimum moves required among all rows and columns.
    int min_moves = 2e9; // Initialize with a very large number

    // Find the minimum in all row totals
    for (int i = 0; i < n; ++i) {
        if (row_moves[i] < min_moves) {
            min_moves = row_moves[i];
        }
    }

    // Find the minimum in all column totals
    for (int j = 0; j < m; ++j) {
        if (col_moves[j] < min_moves) {
            min_moves = col_moves[j];
        }
    }

    // Step 4: Print the final minimum value.
    std::cout << min_moves << std::endl;

    return 0;
}
