import dnest4.classic as dn4
import matplotlib.pyplot as plt
import pandas as pd

output = pd.read_csv("output.csv")
print(dn4.logsumexp(output["logp"]))

plt.plot(output["f"], output["g"], ".", alpha=0.5)
plt.show()
