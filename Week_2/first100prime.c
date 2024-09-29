#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define LIMIT 50000000000LL  // We estimate 50 billion to find 1 billion primes
#define SEGMENT_SIZE 1000000  // Segment size for the segmented sieve

// Function to apply the basic sieve of Eratosthenes up to sqrt(LIMIT)
void simple_sieve(int limit, bool* is_prime, int* small_primes, int* count) {
    for (int i = 2; i <= limit; i++) {
        is_prime[i] = true;
    }

    for (int i = 2; i * i <= limit; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }

    *count = 0;
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            small_primes[(*count)++] = i;
        }
    }
}

// Segmented sieve to find primes in each segment
void segmented_sieve(long long limit, int* small_primes, int small_prime_count, int n) {
    int count = 0;
    for (long long low = 2; low < limit; low += SEGMENT_SIZE) {
        long long high = low + SEGMENT_SIZE - 1;
        if (high >= limit) {
            high = limit - 1;
        }

        // Create a boolean array for the current segment
        bool* is_prime_segment = (bool*)malloc(SEGMENT_SIZE * sizeof(bool));
        for (long long i = 0; i < SEGMENT_SIZE; i++) {
            is_prime_segment[i] = true;
        }

        // Mark non-prime numbers in this segment
        for (int i = 0; i < small_prime_count; i++) {
            long long prime = small_primes[i];

            // Find the minimum number in the segment that is a multiple of the prime
            long long start = (low / prime) * prime;
            if (start < low) {
                start += prime;
            }
            if (start == prime) {
                start += prime;  // Avoid marking the prime itself
            }

            for (long long j = start; j <= high; j += prime) {
                is_prime_segment[j - low] = false;
            }
        }

        // Collect primes from the current segment
        for (long long i = low; i <= high; i++) {
            if (is_prime_segment[i - low]) {
                count++;
                if (count <= n) {
                    printf("%lld ", i);  // Print the prime number
                    if (count % 10 == 0) {
                        printf("\n");  // Print 10 primes per line
                    }
                } else {
                    free(is_prime_segment);
                    return;  // Stop when we have found n primes
                }
            }
        }

        free(is_prime_segment);  // Free the memory used by this segment
    }
}

int main() {
    long long limit = LIMIT;
    int n = 1000000000;  // We want to find the first 1 billion primes

    // Step 1: Find all primes up to sqrt(LIMIT) using a simple sieve
    long long sqrt_limit = (long long)sqrt(limit);
    bool* is_prime_small = (bool*)malloc((sqrt_limit + 1) * sizeof(bool));
    int* small_primes = (int*)malloc((sqrt_limit + 1) * sizeof(int));
    int small_prime_count;

    simple_sieve(sqrt_limit, is_prime_small, small_primes, &small_prime_count);

    // Step 2: Use segmented sieve to find primes up to LIMIT
    printf("The first %d prime numbers are:\n", n);
    segmented_sieve(limit, small_primes, small_prime_count, n);

    free(is_prime_small);
    free(small_primes);

    return 0;
}

//
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define LIMIT 1000  // An estimated upper limit for 100 primes

void sieve_of_eratosthenes(int n) {
    bool is_prime[LIMIT];
    int count = 0;

    // Initialize all numbers as prime
    for (int i = 2; i < LIMIT; i++) {
        is_prime[i] = true;
    }

    // Implement the sieve
    for (int i = 2; i < LIMIT && count < n; i++) {
        if (is_prime[i]) {
            printf("%d ", i);  // Print the prime number
            count++;

            // Mark all multiples of i as not prime
            for (int j = i * i; j < LIMIT; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    int n = 100;
    printf("The first %d prime numbers are:\n", n);
    sieve_of_eratosthenes(n);
    return 0;
}
