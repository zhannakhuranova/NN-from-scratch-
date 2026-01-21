import pandas as pd
import matplotlib.pyplot as plt

# Read CSV
data = pd.read_csv('hello.csv')

# Print actual column names to debug
print("Columns in CSV:", data.columns.tolist())

# Strip any accidental whitespace from column names
data.columns = data.columns.str.strip()

# Now plot
plt.figure(figsize=(10, 6))
plt.plot(data['actual_loss'], label='Loss', color='cyan', linewidth=2)
plt.xlabel('Iteration', fontsize=12)
plt.ylabel('Loss Value', fontsize=12)
plt.title('Neural Network Training - Loss over Time', fontsize=14)
plt.legend(fontsize=10)
plt.grid(True, alpha=0.3)
plt.tight_layout()
plt.show()   
