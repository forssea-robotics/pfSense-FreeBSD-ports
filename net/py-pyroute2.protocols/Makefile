PORTNAME=	pyroute2.protocols
PORTVERSION=	0.6.13
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Netlink library: supplementary protocols
WWW=		https://github.com/svinota/pyroute2/tree/master/pyroute2/protocols

LICENSE=	APACHE20 GPLv2+
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.Apache.v2
LICENSE_FILE_GPLv2+ =	${WRKSRC}/LICENSE.GPL.v2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyroute2>=${PORTVERSION}:net/py-pyroute2@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
