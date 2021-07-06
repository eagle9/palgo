//shaun rewrite from lt dfs idea
//-->same person if there is some common email to both accounts
class Solution {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        Map<String, String> emailToName = new HashMap();
        Map<String, ArrayList<String>> graph = new HashMap();
        for (List<String> account: accounts) {
            String name = account.get(0);
            String firstEmail = account.get(1);
            for (int i = 1; i < account.size(); i++) {
                String email = account.get(i);
            
                //For each account, draw the edge from the first email to all other emails. both directions
                graph.computeIfAbsent(email, x-> new ArrayList<String>()).add(firstEmail);
                graph.computeIfAbsent(firstEmail, x-> new ArrayList<String>()).add(email);
                emailToName.put(email, name);
            }
        }

        Set<String> seen = new HashSet();
        List<List<String>> ans = new ArrayList();
        //try all starting nodes/emails
        for (String email: graph.keySet()) {
            if (!seen.contains(email)) {
                seen.add(email);
                Stack<String> stack = new Stack();
                stack.push(email);
                //dfs from email to find all connected emails/component
                List<String> component = new ArrayList();
                while (!stack.empty()) {
                    String node = stack.pop();
                    component.add(node);
                    for (String nei: graph.get(node)) {
                        if (!seen.contains(nei)) {
                            seen.add(nei);
                            stack.push(nei);
                        }
                    }
                }
                Collections.sort(component);
                //add name to the beginning
                component.add(0, emailToName.get(email));
                ans.add(component);
            }
        }
        return ans;
    }
}
