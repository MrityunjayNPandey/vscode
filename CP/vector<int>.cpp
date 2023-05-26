vector<int> v, v1;
while (list1 != NULL) {
  v.push_back(list1->data);
  list1 = list1->next;
}
while (list2 != NULL) {
  v1.push_back(list2->data);
  list2 = list2->next;
}
vector<int> result;
int carry = 0;
int n = v.size();
int m = v1.size();
for (int i = n - 1, j = m - 1; i >= 0 || j >= 0 || carry > 0; i--, j--) {
  int sum = (i >= 0 ? v[i] : 0) + (j >= 0 ? v1[j] : 0) + carry;
  carry = sum / 10;
  int digit = sum % 10;
  result.insert(result.begin(), digit);
}
struct Node *newll = new Node;
struct Node *ans = newll;
for (int i = 0; i < result.size(); i++) {
  newll->data = result[i];
  if (n != result.size() - 1) {
    struct Node *temp = new Node;
    newll->next = temp;
  }
}
return ans;