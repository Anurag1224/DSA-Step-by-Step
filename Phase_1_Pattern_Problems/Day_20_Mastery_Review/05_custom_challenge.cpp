// ============================================================================
// CAPSTONE 5: Free-Form Pattern Challenge
// ============================================================================
//
// Challenge: Create any custom pattern you want!
//
// Ideas:
// - Your name in ASCII art
// - A shape or object
// - A complex mathematical pattern
// - A custom design combining all techniques
//
// Requirements:
// - Use nested loops
// - Handle n as parameter
// - Scalable to different sizes
// - Clean, readable code
//
// Example: Heart shape, star, mountain, etc.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // TODO: Implement your custom pattern!
    // Replace this with your own creation.
    
    // Starter: Simple double pyramid pattern
    for (int i = 0; i < n; i++) {
        // Left pyramid
        for (int j = 0; j < n - i - 1; j++) cout << " ";
        for (int j = 0; j < 2 * i + 1; j++) cout << "*";
        
        cout << "   ";
        
        // Right pyramid (inverted)
        for (int j = 0; j < i; j++) cout << " ";
        for (int j = 0; j < 2 * (n - i) - 1; j++) cout << "*";
        
        cout << "\n";
    }
    
    return 0;
}

/*
Free-form challenge: Create your own pattern!
Let your creativity shine through.
This is where you truly master pattern thinking.
*/
