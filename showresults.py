import dnest4.classic as dn4
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

output = pd.read_csv("output.csv")
#print(dn4.logsumexp(output["logp"]))

logl = output["f"]/20.0 + output["g"]
log_post = output["logp"] + logl
logz = dn4.logsumexp(log_post)
log_post -= logz
print(logz) # -843.76

high = np.max(log_post) - log_post < 5.0

plt.plot(output["f"], output["g"], ".", markersize=1, alpha=0.5)
plt.plot(output["f"][high], output["g"][high], "r.", markersize=1, alpha=0.5)

plt.show()
