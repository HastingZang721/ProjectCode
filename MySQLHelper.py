import pymysql


class MySQLHelper:
    myVersion = 0.1

    def __init__(self, host, user, password, charset="utf8"):
        self.host = host
        self.user = user
        self.password = password
        self.charset = charset
        try:
            self.conn = pymysql.connect(host=self.host, user=self.user, passwd=self.password)
            #self.conn.set_characters_set(self.charset)
            self.cursor = self.conn.cursor()
        except pymysql.Error as e:
            print('MySql Error : %d %s' % (e.args[0], e.args[1]))

    def setDB(self, db):
        try:
            self.conn.select_db(db)

        except pymysql.Error as e:
            print('MySql Error : %d %s' % (e.args[0], e.args[1]))

    def query(self, sql):
        try:
            rows = self.cursor.execute(sql)
            return rows;
        except pymysql.Error as e:
            print('MySql Error: %s SQL: %s' % (e, sql))

    def queryOnlyRow(self, sql):
        try:
            self.query(sql)
            result = self.cursor.fetchone()
            desc = self.cursor.description
            row = {}
            for i in range(0, len(result)):
                row[desc[i][0]] = result[i]
            return row;
        except pymysql.Error as e:
            print('MySql Error: %s SQL: %s' % (e, sql))

    def queryAll(self, sql):
        try:
            self.query(sql)
            result = self.cursor.fetchall()
            desc = self.cursor.description
            rows = []
            for cloumn in result:
                row = {}
                for i in range(0, len(cloumn)):
                    row[desc[i][0]] = cloumn[i]
                rows.append(row)
            return rows
        except pymysql.Error as e:
            print('MySql Error: %s SQL: %s' % (e, sql))

    # 增删改统一接口
    def updated(self, sql):
        try:
            #self.query("set names 'utf8'")
            self.query(sql)
            self.commit()
        except pymysql.Error as e:
            self.conn.rollback()
            print('MySql Error: %s %s' % (e.args[0], e.args[1]))
        #finally:
            #self.close()


    def insert(self,sql):
        try:
            self.query("set names 'ut8'")
            self.query(sql)
            self.commit()
        except pymysql.Error as e:
            self.conn.rollback()
            print('MySql Error: %s %s' % (e.args[0], e.args[1]))
        #finally:
            self.close()

    def update(self, sql):
        try:
            self.query("set names 'utf8'")
            self.query(sql)
            self.commit()
        except pymysql.Error as e:
            self.conn.rollback()
            print('MySql Error: %s %s' % (e.args[0], e.args[1]))
        finally:
            self.close()

    def delete(self, sql):
        try:
            self.query(sql)
            self.commit()
        except pymysql.Error as e:
            self.conn.rollback()
            print('MySql Error: %s %s' % (e.args[0], e.args[1]))
        finally:
            self.close()

    def getLastInsertRowId(self):
        return self.cursor.lastrowid

    def getRowCount(self):
        return self.cursor.rowcount

    def commit(self):
        self.conn.commit()
    def close(self):
        self.cursor.close()
        self.conn.close()
# # #
# helper = MySQLHelper("127.0.0.1", "root", "root")
# helper.setDB("sg")
# # #
# sql='SELECT COUNT(user_id) FROM weibouser '
# # #sql = "select * from weibouser where reputation<2 order by reputation desc"
# rows = helper.queryAll(sql)
# print(rows)
# e=[]
# for row in rows:
#     print(row['user_id'], row['user_name'])
# #     e.append(row['user_id'])
# fb=open('replow.txt', 'w+')
# fb.write(str(e))
# fb.close()

# sql ='INSERT INTO network_point VALUES("10.2.1.1",1,null,200);'
# helper.insert(sql)

#helper.updated(sql)
#print(helper.getLastInsertRowId())

# sql='UPDATE users SET NAME ="123456" WHERE id="132"'
# helper.update(sql)
# helper.updated(sql)


# sql='DELETE FROM users WHERE id="132"'
# helper.delete(sql)
# helper.updated(sql)
