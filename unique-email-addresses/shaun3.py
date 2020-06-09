class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        set1 = set()
        for email in emails:
            name,host = email.split('@')
            name1 = ""
            for c in name:
                if c == '+': break
                if c == '.': continue
                name1 += c
            set1.add(name1 + '@' + host)
        return len(set1)
