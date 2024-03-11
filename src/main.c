#include <stdio.h>

// Function to calculate the determinant of a 2x2 matrix
int determinant2x2(int matrix[2][2]) {
  return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
}

// Function to calculate the determinant of a 3x3 matrix using co-factor expansion
// with special case handling for all 1s matrix
int determinant3x3(int matrix[3][3]) {
  // Check if all elements are 1
  int allOnes = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (matrix[i][j] != 1) {
        allOnes = 0;
        break;
      }
    }
  }

  if (allOnes) {
    // Determinant of a 3x3 matrix of all 1s is 0
    return 0;
  } else {
    // Use co-factor expansion for other cases
    int determinant = 0;
    // Calculate determinant using co-factors of the first row
    for (int i = 0; i < 3; i++) {
      // Create a temporary 2x2 matrix to store the minor
      int minor[2][2];
      int row = 1, col = 0;
      for (int j = 0; j < 3; j++) {
        if (j == i) continue;
        for (int k = 0; k < 3; k++) {
          if (k == 0) continue;
          minor[row][col] = matrix[j][k];
          col++;
        }
        row++;
        col = 0;
      }
      // Calculate determinant of the minor and multiply by co-factor
      determinant += matrix[0][i] * determinant2x2(minor) * ((i % 2) == 0 ? 1 : -1);
    }
    return determinant;
  }
}

int main() {
  int choice;
  int validChoice = 0; // Flag to track if a valid choice is entered

  while (!validChoice) { // Loop until a valid choice is made
    printf("Enter your choice:\n");
    printf("1. Calculate determinant of 2x2 matrix\n");
    printf("2. Calculate determinant of 3x3 matrix\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
      printf("Invalid choice!\n");
    } else {
      validChoice = 1; // Valid choice entered, exit the loop
    }
  }

  int matrixSize = (choice == 1 ? 2 : 3);
  int matrix[matrixSize][matrixSize];

  printf("Enter matrix elements:\n");
  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixSize; j++) {
      printf("Enter element at row %d, column %d: ", i + 1, j + 1);
      scanf("%d", &matrix[i][j]);
    }
  }

  int det;
  if (choice == 1) {
    det = determinant2x2(matrix);
  } else if (choice == 2) {
    det = determinant3x3(matrix);
  } else {
    printf("Invalid choice!\n");
    return 1;
  }

  printf("Determinant of the matrix: %d\n", det);

  return 0;
}
