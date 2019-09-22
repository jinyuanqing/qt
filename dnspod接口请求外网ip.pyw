import http.client,ast,json
import urllib.parse, urllib.request,requests
import time,webbrowser

import fnmatch
import os

import webbrowser
import locale
import datetime
import re
ip1='1.1.1.1'#ip1设置成空可能会遇到无法访问获取ip的html页的情况.会发生错误.这里设置个永远不会出现的ip,一样达到效果运行就执行一次dns解析
ip=''
while True:
    time.sleep(1)#实现停顿3秒,降低程序消耗
 
       
  
    datetimestring = datetime.datetime.now().strftime('%Y-%m-%d,%H:%M:%S')  # ,在不同输入法下的写法会导致此处值错误.将年月日时分秒转为字符串 也可以写成datetime.datetime.now().strftime('%Y，%m，%d，%w%H，%M，%S，%f') 年月日 星期 时分秒 微秒

    if( (datetime.datetime.now().second)%10==0): #30秒检查一次ip,ip变化就执行dns解析
     #browser = webbrowser  # 实例对象
        #   url1=urllib.request.urlopen('http://www.baidu.com/s?wd=%E6%9C%AC%E6%9C%BAip%E6%9F%A5%E8%AF%A2&rsv_spt=1&rsv_iqid=0xb55ef07500003792&issp=1&f=3&rsv_bp=1&rsv_idx=2&ie=utf-8&tn=baiduhome_pg&rsv_enter=1&oq=%E6%9C%AC%E6%9C%BAip&inputT=9957&rsv_t=d3c3SJwMAAO4t87Ju7nVShhJyaua5yGE9VSNPqbFCpfbPKJRWnwkdQEROZBL6Pk2DOwC&rsv_pq=adc7548b0000e757&rsv_sug2=0&prefixsug=%E6%9C%AC%E6%9C%BAip&rsp=2&rsv_sug7=000&rsv_sug4=10991')
     try:

         url1=requests.get('http://pv.sohu.com/cityjson?ie=utf-8')
         # print(url1.text)
         htmltext=url1.text#结果是:var returnCitySN = {"cip": "113.231.135.151", "cid": "210700", "cname": "辽宁省锦州市"};
         print(htmltext.split("{")[1].split("}")[0])#把页面返回的字符串进行切割("cip": "113.231.135.151", "cid": "210700", "cname": "辽宁省锦州市")为了组成json字符串 var
         ipjson=json.loads('{'+htmltext.split("{")[1].split("}")[0]+'}')#把json形式的字符串转为json
         print(ipjson["cip"])
         ip=ipjson["cip"]
     except Exception  as e:
         print('解析发生异常',e,'时间',datetimestring)
     else:        
        
            #print(html1) 这个获取ip的url无法使用了 http://1212.ip138.com/ic.asp
            #           <center>您的IP是：[113.238.129.215] 来自：辽宁省锦州市 联通</center>
            # str=re.findall('您的IP是.+\d*.]',html1)#结果是['您的IP是：[113.238.130.131]']
            # str=re.findall('[[].+\d*.[]]',html1)#结果是['[113.238.130.131]']以[开始
            # str=re.findall('[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}',html1)#结果是['113.238.130.131']
         # ipstr = re.findall('(([0-9]{1,3}\.){3}[0-9]{1,3})', html1)  # 结果是['113.238.130.131']
         # ''' re.findall('((ab){2}ec)','ababecd')
         #  结果[('ababec', 'ab')]
         # 'ababec',是正则匹配的结果,'ab'是正则(ab)的匹配最后的结果
         # '''
        


          if (ip1!=ip):
            ip1 = ip
            '''
              如果1小时之内，提交了超过5次没有任何变动的记录修改请求，该记录会被系统锁定1小时，不允许再次修改，所以在开发和测试的过程中，请自行处理IP变动，仅在本地                   IP             发生变动的情况下才调用本接口。
               如何理解没有任何变动的记录修改请求？比如原记录值已经是 1.1.1.1，新的请求还要求修改为 1.1.1.1。
            '''
            # 公用的请求体和请求头
            body = urllib.parse.urlencode({'login_token': '15051,85576472f68a00203a09d4c856626847', 'format': 'json'})
            #print(body)
            #print(body.encode('utf-8'))  # 将字符串转成字节.
            headers = {'Content-Type': 'application/x-www-form-urlencoded',
                     #  'User-Agent': 'DDNS Client/2016.06.08 (2838386460@qq.com)'
                       }

            # 获取版本号
            request = urllib.request.Request('https://dnsapi.cn/Info.Version', body.encode('utf-8'), headers)#带有body和headers就是post方法
            #print("测试post方法的请求body",request.data)  # 请求的body,b'login_token=15051%2C85576472f68a00203a09d4c856626847&format=json'
            #print("测试post方法的请求head",request.header_items())  # 请求的head ,[('User-agent', 'DDNS Client/2016.06.08 (2838386460@qq.com)'), ('Content-type', 'application/x-www-form-urlencoded')]
            #print(request.get_method())  # 请求的方法,此处为post
            #print(request.full_url)
            webdata = urllib.request.urlopen(request)  # request实际为构造一个post的url地址,然后将此地址传入urlopen()-使用url打开获得返回值webdata
            ret = webdata.read().decode('utf-8')  # dnspod返回{"status":{"code":"1","message":"4.6","created_at":"2016-06-09 12:14:27"}}
            dicret =ast.literal_eval(ret)  # 将字符串类型的ret转成字典
            #print(type(dicret), dicret)  # {'created_at': '2016-06-09 12:34:55', 'message': '4.6', 'code': '1'}
            print('message:', dicret['status']['message'])  # 找到api的版本message字段

            # 获取帐户信息
            request = urllib.request.Request('https://dnsapi.cn/User.Detail', body.encode('utf-8'), headers)
            webdata = urllib.request.urlopen(request)  # request实际为构造一个post的url地址,然后将此地址传入urlopen()-使用url打开获得返回值webdata
            ret = webdata.read().decode('utf-8')  # dnspod返回{"status":{"code":"1","message":"Action completed successful","created_at":"2016-06-10 10:21:48"},"info":{"user":{"weixin_binded":"yes","agent_pending":false,"nick":"\u91d1 \u5148\u751f","balance":0,"smsbalance":0,"is_dtoken_on":false,"id":"1359987","email":"2838386460@qq.com","qq":"2838386460","status":"enabled","telephone":"15241366729","email_verified":"yes","telephone_verified":"yes","user_grade":"DP_Free","real_name":"","user_type":"personal","im":""}}}
            #print('账户信号返回',(ret))
            dicret=json.loads(ret) # 将含有JOSON字符串类型的转成(字典) 方法1
            #JIOSN2=json.JSONDecoder().decode(json1)#将含有JOSON字符串类型的转成python的(字典) 方法2
            #print(type(dicret), dicret)  # {'created_at': '2016-06-09 12:34:55', 'message': '4.6', 'code': '1'}
            #print(dicret["info"]["user"]["nick"])#user下的昵称

            # 获取域名列表
            request = urllib.request.Request('https://dnsapi.cn/Domain.List', body.encode('utf-8'), headers)
            webdata = urllib.request.urlopen(request)  # request实际为构造一个post的url地址,然后将此地址传入urlopen()-使用url打开获得返回值webdata
            ret = webdata.read().decode('utf-8')  # dnspod返回{"status":{"code":"1","message":"Action completed successful","created_at":"2016-06-10 10:21:48"},"info":{"user":{"weixin_binded":"yes","agent_pending":false,"nick":"\u91d1 \u5148\u751f","balance":0,"smsbalance":0,"is_dtoken_on":false,"id":"1359987","email":"2838386460@qq.com","qq":"2838386460","status":"enabled","telephone":"15241366729","email_verified":"yes","telephone_verified":"yes","user_grade":"DP_Free","real_name":"","user_type":"personal","im":""}}}
            #print('域名列表返回',(ret))
            dicret=json.loads(ret) # 将含有JOSON字符串类型的转成(字典) 方法1
            #JIOSN2=json.JSONDecoder().decode(json1)#将含有JOSON字符串类型的转成python的(字典) 方法2
            #print(type(dicret), dicret)  # {'created_at': '2016-06-09 12:34:55', 'message': '4.6', 'code': '1'}
            #返回{'domains': [{'name': 'yxzhw.cf', 'is_mark': 'no', 'owner': '2838386460@qq.com', 'punycode': 'yxzhw.cf', 'searchengine_push': 'yes', 'remark': '', 'grade_title': '新免费套餐', 'grade': 'DP_Free', 'cname_speedup': 'disable', 'ext_status': 'dnserror', 'group_id': '1', 'created_on': '2016-01-19 15:58:38', 'ttl': '600', 'status': 'enable', 'is_vip': 'no', 'id': 30367425, 'records': '4', 'updated_on': '2016-01-19 15:58:38'}, {'name': 'yxzh.cf', 'is_mark': 'no', 'owner': '2838386460@qq.com', 'punycode': 'yxzh.cf', 'searchengine_push': 'yes', 'remark': '', 'grade_title': '新免费套餐', 'grade': 'DP_Free', 'cname_speedup': 'disable', 'ext_status': '', 'group_id': '1', 'created_on': '2015-12-11 19:48:43', 'ttl': '600', 'status': 'enable', 'is_vip': 'no', 'id': 28636341, 'records': '4', 'updated_on': '2016-01-15 12:56:01'}, {'name': 'yxzhw.ga', 'is_mark': 'no', 'owner': '2838386460@qq.com', 'punycode': 'yxzhw.ga', 'searchengine_push': 'yes', 'remark': '', 'grade_title': '新免费套餐', 'grade': 'DP_Free', 'cname_speedup': 'disable', 'ext_status': 'notexist', 'group_id': '1', 'created_on': '2016-01-14 19:43:19', 'ttl': '600', 'status': 'enable', 'is_vip': 'no', 'id': 30055131, 'records': '2', 'updated_on': '2016-01-14 19:43:19'}, {'name': 'yxzh.tk', 'is_mark': 'no', 'owner': '2838386460@qq.com', 'punycode': 'yxzh.tk', 'searchengine_push': 'yes', 'remark': '', 'grade_title': '免费套餐', 'grade': 'D_Free', 'cname_speedup': 'disable', 'ext_status': 'notexist', 'group_id': '1', 'created_on': '2013-04-03 09:45:50', 'ttl': '600', 'status': 'enable', 'is_vip': 'no', 'id': 3171810, 'records': '2', 'updated_on': '2016-01-14 19:43:01'}, {'name': 'yxzhw.cn', 'is_mark': 'no', 'owner': '2838386460@qq.com', 'punycode': 'yxzhw.cn', 'searchengine_push': 'yes', 'remark': '', 'grade_title': '新免费套餐', 'grade': 'DP_Free', 'cname_speedup': 'disable', 'ext_status': '', 'group_id': '1', 'created_on': '2015-10-12 19:18:04', 'ttl': '600', 'status': 'enable', 'is_vip': 'no', 'id': 26587099, 'records': '5', 'updated_on': '2015-10-12 19:18:04'}], 'info': {'share_out_total': 0, 'pause_total': 0, 'vip_expire': 0, 'spam_total': 0, 'vip_total': 0, 'ismark_total': 0, 'error_total': 3, 'share_total': 0, 'all_total': 5, 'domain_total': 5, 'lock_total': 0, 'mine_total': 5}, 'status': {'message': 'Action completed successful', 'code': '1', 'created_at': '2016-06-10 16:48:02'}}
            domain=[]#存放域名id的列表
            for i in range(0,dicret["info"]["domain_total"]):
               # assert isinstance(i, object)
                domain.append(dicret["domains"][i]["id"])#将域名id插入到列表domain中
                print('域名id',domain[i],'域名',dicret["domains"][i]["name"],'域名状态',dicret["domains"][i]["status"])#domains是字典,内部是列表.字典的获取是["字典元素名称"];列表获取是[0,1,2]



            # 获取域名的记录列表,
                body = urllib.parse.urlencode(
                 {'login_token': '15051,85576472f68a00203a09d4c856626847', 'format': 'json', 'domain_id': domain[i]})
                request = urllib.request.Request('https://dnsapi.cn/Record.List', body.encode('utf-8'), headers)
                webdata = urllib.request.urlopen(request)  # request实际为构造一个post的url地址,然后将此地址传入urlopen()-使用url打开获得返回值webdata
                # time.sleep(3)
                ret = webdata.read().decode(
                 'utf-8')  # dnspod返回{"status":{"code":"1","message":"Action completed successful","created_at":"2016-06-10 10:21:48"},"info":{"user":{"weixin_binded":"yes","agent_pending":false,"nick":"\u91d1 \u5148\u751f","balance":0,"smsbalance":0,"is_dtoken_on":false,"id":"1359987","email":"2838386460@qq.com","qq":"2838386460","status":"enabled","telephone":"15241366729","email_verified":"yes","telephone_verified":"yes","user_grade":"DP_Free","real_name":"","user_type":"personal","im":""}}}
                #print('记录返回', ret)
                dicret1 = json.loads(ret)  # 将含有JOSON字符串类型的转成(字典) 方法1
                # JIOSN2=json.JSONDecoder().decode(json1)#将含有JOSON字符串类型的转成python的(字典) 方法2
                #print(type(dicret1), dicret1)  # {'created_at': '2016-06-09 12:34:55', 'message': '4.6', 'code': '1'}

                #更新动态DNS 更新后域名的A记录直接更改域名ip为运行此程序的pc的外网ip. -login_token=LOGIN_TOKEN&format=json&domain_id=2317346&record_id=16894439&record_line=默认&sub_domain=www'
                #p=input('请输入你要修改的域名id:')

                #域名解析的方法:
                #从域名列表中获取login_token,domain_id,record_id,record_line,sub_domain等填入 body = urllib.parse.urlencode(参数)里
                
                #域名id 26587099 域名 yxzhw.cn 域名状态 enable 动态更新dns部分
                body = urllib.parse.urlencode(
                 {'login_token': '15051,85576472f68a00203a09d4c856626847', 'format': 'json', 'domain_id': '26587099','record_id':'135998714','record_line':'默认','sub_domain':'@'})#域名yxzhw.cn的dns更新
                request = urllib.request.Request('https://dnsapi.cn/Record.Ddns', body.encode('utf-8'), headers)
                webdata = urllib.request.urlopen(request)  # request实际为构造一个post的url地址,然后将此地址传入urlopen()-使用url打开获得返回值webdata
                ret = webdata.read().decode(
                 'utf-8')  # dnspod返回{"status":{"code":"1","message":"Action completed successful","created_at":"2016-06-10 10:21:48"},"info":{"user":{"weixin_binded":"yes","agent_pending":false,"nick":"\u91d1 \u5148\u751f","balance":0,"smsbalance":0,"is_dtoken_on":false,"id":"1359987","email":"2838386460@qq.com","qq":"2838386460","status":"enabled","telephone":"15241366729","email_verified":"yes","telephone_verified":"yes","user_grade":"DP_Free","real_name":"","user_type":"personal","im":""}}}
                #print('DDNS返回', ret)
                dicret1 = json.loads(ret)  # 将含有JOSON字符串类型的转成(字典) 方法1
                # JIOSN2=json.JSONDecoder().decode(json1)#将含有JOSON字符串类型的转成python的(字典) 方法2
                #print(type(dicret1), dicret1)  # {'created_at': '2016-06-09 12:34:55', 'message': '4.6', 'code': '1'}


                # 域名id 49460139 域名 52wangwei.cn 域名状态 enable动态更新dns部分
                '''查看程序输出.查找(这是用于52wangwei.cn域名的解析参数)<class 'dict'> {'status': {'code': '1', 'message': 'Action completed successful', 'created_at': '2017-02-08 18:17:44'}, 'domain': {'id': 49460139, 'name': '52wangwei.cn', 'punycode': '52wangwei.cn', 'grade': 'DP_Free', 'owner': '2838386460@qq.com', 'ext_status': '', 'ttl': 600, 'min_ttl': 600, 'dnspod_ns': ['f1g1ns1.dnspod.net', 'f1g1ns2.dnspod.net'], 'status': 'enable'}, 'info': {'sub_domains': '4', 'record_total': '4'}, 'records': [{'id': '248140825', 'ttl': '10', 'value': '113.231.133.45', 'enabled': '1', 'status': 'enabled', 'updated_on': '2017-02-05 20:24:09', 'name': '@', 'line': '默认', 'line_id': '0', 'type': 'A', 'weight': None, 'monitor_status': '', 'remark': '', 'use_aqb': 'no', 'mx': '0'}, {'id': '248140330', 'ttl': '86400', 'value': 'f1g1ns1.dnspod.net.', 'enabled': '1', 'status': 'enabled', 'updated_on': '2016-11-02 17:16:14', 'name': '@', 'line': '默认', 'line_id': '0', 'type': 'NS', 'weight': None, 'monitor_status': '', 'remark': '', 'use_aqb': 'no', 'mx': '0', 'hold': 'hold'}, {'id': '248140331', 'ttl': '86400', 'value': 'f1g1ns2.dnspod.net.', 'enabled': '1', 'status': 'enabled', 'updated_on': '2016-11-02 17:16:14', 'name': '@', 'line': '默认', 'line_id': '0', 'type': 'NS', 'weight': None, 'monitor_status': '', 'remark': '', 'use_aqb': 'no', 'mx': '0', 'hold': 'hold'}, {'id': '248140826', 'ttl': '600', 'value': '52wangwei.cn.', 'enabled': '1', 'status': 'enabled', 'updated_on': '2016-11-02 17:18:48', 'name': 'www', 'line': '默认', 'line_id': '0', 'type': 'CNAME', 'weight': None, 'monitor_status': '', 'remark': '', 'use_aqb': 'no', 'mx': '0'}]}'''
                body = urllib.parse.urlencode(
                    {'login_token': '15051,85576472f68a00203a09d4c856626847', 'format': 'json', 'domain_id': '49460139',
                     'record_id': '248140825', 'record_line': '默认', 'sub_domain': '@'})  # 域名52wangwei.cn的dns更新 需要更改domain_id ，record_id -》来自于域名’记录返回‘ -》  records":[{"id":"135998714","name":"@","line":"\u9ed8\u8ba4","line_id":"0","type":"A","ttl":"10","value":"113.238.135.88","
                request = urllib.request.Request('https://dnsapi.cn/Record.Ddns', body.encode('utf-8'), headers)
                webdata = urllib.request.urlopen(request)  # request实际为构造一个post的url地址,然后将此地址传入urlopen()-使用url打开获得返回值webdata
                ret = webdata.read().decode(
                    'utf-8')  # dnspod返回{"status":{"code":"1","message":"Action completed successful","created_at":"2016-06-10 10:21:48"},"info":{"user":{"weixin_binded":"yes","agent_pending":false,"nick":"\u91d1 \u5148\u751f","balance":0,"smsbalance":0,"is_dtoken_on":false,"id":"1359987","email":"2838386460@qq.com","qq":"2838386460","status":"enabled","telephone":"15241366729","email_verified":"yes","telephone_verified":"yes","user_grade":"DP_Free","real_name":"","user_type":"personal","im":""}}}
                #print('DDNS返回', ret)
                dicret1 = json.loads(ret)  # 将含有JOSON字符串类型的转成(字典) 方法1
                # JIOSN2=json.JSONDecoder().decode(json1)#将含有JOSON字符串类型的转成python的(字典) 方法2
                #print(type(dicret1), dicret1)  # {'created_at': '2016-06-09 12:34:55', 'message': '4.6', 'code': '1'}


                   # 域名id 49460139 域名 yxzhw.cf 域名状态 enable动态更新dns部分
                body = urllib.parse.urlencode(
                    {'login_token': '15051,85576472f68a00203a09d4c856626847', 'format': 'json', 'domain_id': '30367425',
                     'record_id': '141576989', 'record_line': '默认', 'sub_domain': '@'})  # 域名yxzhw.cf的dns更新 需要更改domain_id ，record_id -》来自于域名’记录返回‘ -》  records":[{"id":"135998714","name":"@","line":"\u9ed8\u8ba4","line_id":"0","type":"A","ttl":"10","value":"113.238.135.88","
                request = urllib.request.Request('https://dnsapi.cn/Record.Ddns', body.encode('utf-8'), headers)
                webdata = urllib.request.urlopen(request)  # request实际为构造一个post的url地址,然后将此地址传入urlopen()-使用url打开获得返回值webdata
                ret = webdata.read().decode(
                    'utf-8')  # dnspod返回{"status":{"code":"1","message":"Action completed successful","created_at":"2016-06-10 10:21:48"},"info":{"user":{"weixin_binded":"yes","agent_pending":false,"nick":"\u91d1 \u5148\u751f","balance":0,"smsbalance":0,"is_dtoken_on":false,"id":"1359987","email":"2838386460@qq.com","qq":"2838386460","status":"enabled","telephone":"15241366729","email_verified":"yes","telephone_verified":"yes","user_grade":"DP_Free","real_name":"","user_type":"personal","im":""}}}
                #print('DDNS返回', ret)
                dicret1 = json.loads(ret)  # 将含有JOSON字符串类型的转成(字典) 方法1
                # JIOSN2=json.JSONDecoder().decode(json1)#将含有JOSON字符串类型的转成python的(字典) 方法2
                #print(type(dicret1), dicret1)  # {'created_at': '2016-06-09 12:34:55', 'message': '4.6', 'code': '1'}

