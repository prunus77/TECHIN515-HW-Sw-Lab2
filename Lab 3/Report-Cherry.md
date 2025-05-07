## Discussion

### 1. Evaluating Question Relevance

Following both feature importance analysis using various decision tree algorithms and real-world user testing, it became clear that not all quiz questions offered meaningful differentiation between house outcomes.

| ID  | Question                               | Importance | Commentary                                                    |
| --- | -------------------------------------- | ---------- | ------------------------------------------------------------- |
| Q1  | What do you value most?                | 18%        | Strong determinant—key for distinguishing bravery vs. loyalty |
| Q2  | How would you react to cheating?       | 15%        | Captures ethical vs. pragmatic thinking clearly               |
| Q3  | Favorite academic subject?             | 12%        | Useful for splitting Ravenclaw and Slytherin                  |
| Q4  | How do you approach challenges?        | 10%        | Some overlap with Q1, but still useful                        |
| Q5  | How do your friends see you?           | 11%        | Redundant with Q1 but carries moderate signal                 |
| Q6  | What would you do with a mystery book? | 2%         | Rarely influenced decisions; felt unnatural to users          |
| Q7  | Preferred magical creature?            | 9%         | Slight bias between Gryffindor and Ravenclaw                  |
| Q8  | Your approach to problem solving?      | 8%         | Complements Q4 with subtle variation                          |
| Q9  | Most valued trait in a friend?         | 3%         | Overlaps significantly with Q2                                |
| Q10 | Ideal magical career?                  | 12%        | Helpful for separating Hufflepuff and Slytherin profiles      |

#### Streamlining

* **Q6 ("mystery book")** was removed due to minimal predictive value and poor user engagement. Accuracy dropped by just \~1–2%.
* **Q9 ("friend trait")** was excluded because of its redundancy with Q2. Its removal improved flow and reduced quiz fatigue.

**Updated Result**: With 8 refined questions, our retrained decision tree achieved **83% accuracy**—a slight tradeoff from the original 85% but led to a noticeably smoother quiz experience, per user feedback.

---

### 2. Model and System Optimization

#### Algorithmic Enhancements

* **Tree Pruning**: Leveraged cost-complexity pruning (`ccp_alpha`) to avoid overfitting, improving generalization on limited data.
* **Voting Ensemble**: Integrated a lightweight ensemble (3–5 trees, shallow depth) to balance noise and improve decision stability without increasing latency.
* **Threshold Quantization**: Converted float thresholds into 8-bit integers to accelerate decision-making on embedded hardware (ESP32-class devices).

#### Hardware and UX Upgrades

* **Rotary Input Dial**: Replaced multiple buttons with a rotary encoder + press action—simplifies circuit design and feels more natural.
* **Touch-Based Controls**: Capacitive touch sensors streamline the UI with zero moving parts and a cleaner look.
* **LED Reveal Sequence**: Animated RGB ring (NeoPixel) adds anticipation before house assignment, enhancing user engagement.
* **Tactile/Auditory Feedback**: Integrated haptic or buzzer response provides real-time input confirmation.

---

### 3. Future-Ready Design: Sensor Inputs & Model Scaling

* For **basic analog data** (e.g., light, sound, proximity), discretizing readings into categories (e.g., 1–4) enables continued use of decision trees.
* For **complex or continuous inputs**, such as audio patterns or gesture signals, a small neural network (e.g., 1–2 dense layers in TensorFlow Lite) becomes more effective. These models can capture nonlinear interactions that decision trees often miss.
