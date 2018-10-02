/**
 * Definition of Document:
 * public class Document {
 *     public int id;
 *     public String content;
 * }
 */
public class Solution {
    /**
     * @param docs a list of documents
     * @return an inverted index
     */
	
	public Map<String, List<Integer>> invertedIndex(List<Document> docs) {
        Map<String, List<Integer>> table = new Map<>();
        for (Document doc : docs) {
            int id = doc.id;
            String s;
            stringstream ss(doc.content);
            while (getline(ss, s, ' '))
            {
                if (s.size() && (table[s].size() == 0 || table[s].back() != id))
                {
                    table[s].push_back(id);
                }
            }
        }
        
        return table;
    }
};
